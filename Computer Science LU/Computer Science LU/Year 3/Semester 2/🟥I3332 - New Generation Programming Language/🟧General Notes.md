![[207 - Terms.png]]

# Errors

## the connectionstring property has not been initialized.
go to `appsettings.json` and add this:
```json
{
  "ConnectionStrings": {
    "ConnectionString": "localhost:7242"
  }
  //...
}
```
