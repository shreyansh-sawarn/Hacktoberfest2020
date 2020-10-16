import model_class as md
import model_train as mt

#Preparing test data and loading model

test_data = mt.test_data

split = md.DataSplitting(test_data)

X_test, Y_test = split.feature_label_split("G3", test_data) 

X_prepared = md.final_pipeline.fit_transform(X_test)

model = md.load("marks_predictor")

# Result using cross validation

result_mse = md.cross_val_score(model, X_prepared, Y_test, scoring = "neg_mean_squared_error", cv = 10)

result_rmse = md.np.sqrt(-result_mse)

md.test(result_rmse)
 
