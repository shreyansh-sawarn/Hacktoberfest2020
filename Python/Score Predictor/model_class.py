import pandas as pd
from sklearn.preprocessing import LabelEncoder
import numpy as np
from sklearn.base import BaseEstimator, TransformerMixin
from sklearn.pipeline import FeatureUnion, Pipeline 
from sklearn.impute import SimpleImputer
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score
from joblib import load, dump
from sklearn.metrics import mean_squared_error
from sklearn.preprocessing import OneHotEncoder

# To select specific columns from the dataframe 

class FeatureSelector(BaseEstimator, TransformerMixin):

    def __init__(self, feature):
        self.feature = feature

    def fit(self, df):
        return self

    def transform(self, df):
        return df[self.feature]


# To encode categorical data

class EncodingCategoricalData(BaseEstimator, TransformerMixin):

    def __init__(self, df = None):
        self.df = df

    def fit(self, df):
        return self

    def transform(self, df):

        self.df = df
        self.new_df = pd.DataFrame( columns = df.columns)
        
        columns = np.array(self.df.columns)
       
        label_encoder = LabelEncoder()

        for column in columns:
            
            self.new_df[column] = label_encoder.fit_transform(self.df[column])

        return self.new_df



# Pipelines

categorical_list = ["school", "sex", "address", "famsize", "Pstatus", "Mjob", "Fjob", "reason", "guardian", "schoolsup", "famsup", "paid", "activities", "nursery", "higher", "internet", "romantic"]

numerical_list = ["age", "Medu", "Fedu", "traveltime", "studytime", "failures", "famrel", "freetime", "goout", "Dalc", "Walc", "health", "absences", "G1", "G2"]


categorical_pipeline = Pipeline(steps = [

    ("feature_selector", FeatureSelector(categorical_list)), 
    ("encoder", EncodingCategoricalData()), 
    ("imputer", SimpleImputer(strategy = 'most_frequent'))
    
])

numerical_pipeline = Pipeline(steps = [
    ("feature_selector", FeatureSelector(numerical_list)), 
    ("imp", SimpleImputer(strategy = 'median'))
])

final_pipeline = FeatureUnion( transformer_list = [
    
    ("category-pipeline", categorical_pipeline),
    ("numerical-pipline", numerical_pipeline)

] )

final_pipeline_m = Pipeline(steps = [
    ("f-pipeline", final_pipeline),
    ("model", LinearRegression())
])


# function for train test split

class DataSplitting:

    def __init__(self, data):
        self.data = data


    def train_test_split(self,data, test_percentage, random):

        np.random.seed(random)

        shuffled_data = np.random.permutation(len(data))

        test_data_size = int(test_percentage*len(data))

        test_data_indices = shuffled_data[:test_data_size]

        train_data_indices = shuffled_data[test_data_size:]

        return data.iloc[train_data_indices], data.iloc[test_data_indices]

    def feature_label_split(self, label, data):

        X = data.drop(label, axis = 1)

        Y = pd.DataFrame(data[label])

        return X, Y

# A simple function to show mean, standard deviation and root mean square error

def test(rmse):
    print("RMSE : ", rmse)
    print("MEAN : ", rmse.mean())
    print("STD DEVIATION", rmse.std())