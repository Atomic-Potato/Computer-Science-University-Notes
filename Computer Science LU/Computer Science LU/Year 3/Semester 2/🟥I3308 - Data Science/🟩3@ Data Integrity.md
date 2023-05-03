# Domains
In ArcGIS, a domain is a set of rules that define the valid values for a field in a table or feature class. Domains can be used to standardize the values entered into a field, enforce data integrity, and make it easier to edit and maintain data.

There are three types of domains in ArcGIS:
1. `Coded value domain:` A coded value domain is a domain that uses a set of pre-defined values to restrict the values that can be entered into a field. 
   *For example, you might use a coded value domain to restrict the values entered into a "land use" field to a set of standardized land use categories, such as "residential," "commercial," and "industrial."*
2. `Range domain:` A range domain is a domain that restricts the values that can be entered into a field to a specified range of values. 
   *For example, you might use a range domain to restrict the values entered into a "temperature" field to a range of -40 to 100 degrees Celsius.* 
3. `Text domain:` A text domain is a domain that restricts the values that can be entered into a field to a specified length and format. 
   *For example, you might use a text domain to restrict the values entered into a "postal code" field to a specific format, such as "A1A 1A1" in Canada or "12345" in the United States.*

## Creating domains
