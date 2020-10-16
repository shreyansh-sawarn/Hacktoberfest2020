import model_class as md

# Preparing training data and dumping the model

data = md.pd.read_csv("port.csv")

split = md.DataSplitting(data)

train_data, test_data = split.train_test_split(data, 0.2, 42)

X_train, Y_train = split.feature_label_split("G3", train_data)

X_prepared = md.final_pipeline.fit_transform(X_train)

model = md.LinearRegression()

model.fit(X_prepared, Y_train)

md.dump(model, "marks_predictor")

