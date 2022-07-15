# Data Validation
```python
import pandas as pd

students1 = pd.Series({'Bilal': '92215', 'Mariam': '3310'})

students1.str.match(r'\d{5}')
#Bilal True 
#Mariam False 
#dtype: bool
```
Sometimes, rather than matching an entire value to a pattern, you’ll want to know whether a value contains a substring that matches the pattern. In this case, use method `contains` instead of match.

```python
students2 = pd.Series(['Bilal, CS 92215', 'Mariam, ST 33101'])
students2.str.contains(r' [A-Z]{2} ')
#0 True 
#1 True 
#dtype: bool
students2.str.match(r' [A-Z]{2} ')
#0 False 
#1 False 
#dtype: bool
```

# Reformatting Data
```python
contacts = [['Malak', 'malak@demo.com', '55555555'],
			['Samir', 'samir@demo.com', '55551234']]

contactsdf = pd.DataFrame(contacts, columns=['Name', 'Email', 'Phone'])
```

We can map the phone numbers to the proper format by calling the Series method `map` on the DataFrame’s 'Phone' column. 
Method `map`’s argument is a function that receives a value and returns the mapped value. The function `get_formatted_phone` maps 8 consecutive digits into the format ##-###-###:

```python
def get_formatted_phone(value):
	result = re.fullmatch(r'(\d{2})(\d{3})(\d{3})', value)
	return '-'.join(result.groups()) if result else value
```
Series method map returns a new Series containing the results of calling its function argument for each value in the column.
```python
formatted_phone = contactsdf['Phone'].map(get_formatted_phone)
#0 55-555-555 
#1 55-551-234 
#Name: Phone, dtype: object
```

Once you’ve confirmed that the data is in the correct format, you can update it in the original DataFrame by assigning the new Series to the 'Phone' column.
```python
contactsdf['Phone'] = formatted_phone
```
![[Pasted image 20220129182208.png]]