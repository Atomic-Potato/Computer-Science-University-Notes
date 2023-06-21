K-fold Cross Validation is a model validation technique for
assessing how the results of a statistical analysis will generalize to
an independent data set.

It is mainly used in settings where the goal is prediction, and one
wants to estimate how accurately a predictive model will
perform in practice.

In a prediction problem, a model is usually given a dataset of
known data on which training is run *(training dataset)*, and a
dataset of unknown data against which the model is tested
*(validation dataset or testing set)*

# Cross Validation
The goal of cross validation is to define a validation set, in order to:
- Limit problems like overfitting
  > **==DEFINITION:==** Overfitting is when we train a model over single data set, and this model will only fit this set of data and introducing new data to the model will most likely not fit this data.
- Give an insight on how the model will generalize to an independent dataset in a real case scenario for instance

# Algorithm
![[Pasted image 20230620162544.png]]

![[Pasted image 20230620163000.png]]

> **==NOTE:==** Usually when calculating the NRMSE, we take the y mean of the validation set.

# Comparing models
To compare models, we can simply apply Cross Validation for both, and **who has the least Cross Validation is more effective.**

# LOOCV
![[Pasted image 20230620162733.png]]