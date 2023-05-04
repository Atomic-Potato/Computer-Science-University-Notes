

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
Domains are shared for the entire database.

Right click the database and click domains
![[Pasted image 20230504134710.png]]

This will open the domains creation tab
![[Pasted image 20230504134817.png]]

once a domain is created you can add a domain to a field by right clicking the desired feature class -> Data Design -> Fields
![[Pasted image 20230504135323.png]]
![[Pasted image 20230504135435.png]]

We have also another method by first using the [[🟩1@ ArcGIS#Frequency|frequency]] tool on the desired table and then use the [[🟩1@ ArcGIS#Table To Domain|Table To Domain]] tool on the resulting frequency table.

# Subtypes
Subtypes are a way to group features in a feature class based on a common set of attributes. In ArcGIS, a subtype is defined as a subset of features within a feature class that share the same attribute schema. By creating subtypes, you can organize your features into logical groups and enforce data integrity by restricting attribute values.

![[Pasted image 20230504141557.png]]

## Creating Subtypes
For the desired [[🟩2@ Geodatabase#^d0b334|feature class]] we have to create an integer type value *(favorably create a domain for it as well)*. The integer will be used to indicate the subtype of the [[🟩1@ ArcGIS#^763d56|feature]].

Now to create subtypes, simply right click the [[🟩2@ Geodatabase#^d0b334|feature class]] and go to subtypes, and create your subtype, bam boom bap u got subtypes.
![[Pasted image 20230504142652.png]]
![[Pasted image 20230504142659.png]]
