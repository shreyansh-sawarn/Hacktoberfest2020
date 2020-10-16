from flask import Flask, url_for, render_template, request, redirect, flash
import joblib as jb
import numpy as np
import pandas as pd
import model_class as md
import model_train as mt

app = Flask(__name__, template_folder = "template")

model = jb.load("marks_predictor")

@app.route('/')
def hello_world():
    return render_template('index.html')


@app.route('/score_predict',methods = ['POST', 'GET'])

def score_predict():
  
  inputs = []

  values = request.form

  for i in range(1, 33):
    j = str(i)
    inputs.append(values[j])

  
  data = np.array([inputs])

  data_df = pd.DataFrame(data, columns = mt.X_train.columns)

  data_transform = md.final_pipeline.fit_transform(data_df)
  
  result = model.predict(data_transform)

  output='{0:.{1}f}'.format(result[0][0], 2)
      







  return render_template("index.html", pred = "Your expected score is : {}".format(output))





    


 
    



if __name__ == '__main__':
   app.run(debug=True)

   