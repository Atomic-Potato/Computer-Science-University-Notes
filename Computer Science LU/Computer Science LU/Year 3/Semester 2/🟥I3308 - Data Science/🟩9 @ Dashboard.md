A dashboard is basically creating an interactive representation of the data from a [[🟩7 @ Sharing|Web Map or a Web Layer]].

![[Pasted image 20230601133922.png]]

The benefits of a dashboard:
- Easy to understand
- Ready to use
- Interactive
- Flexible 
- Configurable

# Dashboard Elements
![[Pasted image 20230601134351.png]]

# Creating a Dashboard
One way is to create it directly from the map viewer
![[Pasted image 20230601134627.png]]
Now you can go nutz and customize your dashboard


# Customizing The Dashboard With Arcade
If you go to an element settings and enable `Advanced Formatting`, it will show convert all of the settings so that you can directly modify their code.
![[Pasted image 20230601135154.png]]
==Note:== Switching to advanced formatting wont let you switch back to the original settings view.

![[Pasted image 20230601135331.png]]

To make your indicator dynamic, you can use if statements after the desired field:
```css
fieldName: IIF(condition, true_value, false_value)
```

# Data Filters
Theres a filtering option, das it
![[Pasted image 20230601135655.png]]

# Chart Element Categories
Depending on your data you use a specific category for the chart element

1. Grouped Values:
    - Grouped Values category allows you to create a chart where the data is grouped or aggregated based on a specific field in your dataset.
    - You can choose a field from your dataset that contains categorical or discrete values, such as "year," "region," or "category."
    - The chart will display separate data series or bars for each unique value in the chosen field, showing the distribution or comparison of values across the groups.
2. Features:
    - Features category allows you to create a chart where each individual feature or record in your dataset represents a separate data point in the chart.
    - You can choose fields from your dataset to represent different aspects of the chart, such as the x-axis and y-axis values.
    - The chart will display data points for each feature, showing the relationship or distribution of values based on the chosen fields.
3. Fields:
    - Fields category allows you to create a chart by selecting specific fields from your dataset to represent different aspects of the chart.
    - You can choose fields to represent the x-axis, y-axis, series, and other properties of the chart.
    - The chart will display the selected fields, providing a visual representation of the data based on their values.

![[Pasted image 20230601135954.png]]

# Selectors
Selectors are basically filters for the entire dashboard
![[Pasted image 20230601140752.png]]

## Category Selector
![[Pasted image 20230601141023.png]]
1. Defined Value:
    - When selecting "Defined value" in the category selector, you manually specify the categories or values that will be available for selection.
    - This option is useful when you want to provide a specific set of predetermined values or categories that users can choose from.
    - You manually enter the values or categories, and they will be displayed as options in the selector for users to select.
2. Features:
    - When choosing "Features" in the category selector, the available categories are derived from the features present in the selected dataset or layer.
    - Each unique feature in the dataset will be listed as a category in the selector.
    - This option is useful when you want users to select individual features or records as categories to filter or explore the data associated with each feature.
3. Grouped Values:
    - "Grouped values" allows you to group the categories based on the values of a specific field in the dataset.
    - You choose a field from the dataset that contains categorical or discrete values, and the selector will display the unique values from that field as categories.
    - This option is useful when you want to present the available categories based on a particular field's values, enabling users to filter or analyze data within those grouped categories.

## ==Note==
There a couple more things about selectors but i cant be assed anymore.