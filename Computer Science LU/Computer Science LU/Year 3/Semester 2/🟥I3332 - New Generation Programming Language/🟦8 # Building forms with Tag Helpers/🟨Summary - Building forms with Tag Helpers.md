*important bits are ==highlighted==*

---

- With Tag Helpers, you can bind your data model to HTML elements, making it easier to generate dynamic HTML while remaining editor friendly.
- As with Razor in general, Tag Helpers are for server-side rendering of HTML only. You can’t use them directly in frontend frameworks, such as Angular or React.
- Tag Helpers can be standalone elements or can attach to existing HTML using attributes. This lets you both customize HTML elements and add entirely new elements.
- Tag Helpers can customize the elements they’re attached to, add additional attributes, and customize how they’re rendered to HTML. This can greatly reduce the amount of markup you need to write.
- Tag Helpers can expose multiple attributes on a single element. This makes it easier to configure the Tag Helper, as you can set multiple, separate, values.
- ==You can add the `asp-page` and `asp-page-handler` attributes to the `<form>` element to set the action URL using the URL generation feature of Razor Pages.==
- ==You specify route values to use during routing with the Form Tag Helper using `asp-route-*` attributes. These values are used to build the final URL or are passed as query data.==
- The **Form Tag Helper** also generates a hidden field that you can use to prevent CSRF attacks. This is added automatically and is an important security measure.
- ==You can attach the **Label Tag Helper** to a `<label>` using `asp-for`. It generates an appropriate for attribute and caption based on the `[Display]` Data-Annotations attribute and the `PageModel` property name.==
- ==The **Input Tag Helper** sets the type attribute of an `<input>` element to the appropriate value based on a bound property’s Type and any `DataAnnotations` applied to it. It also generates the `data-val-*` attributes required **for client-side validation.**==This significantly reduces the amount of HTML code you need to write.
- ==To enable **client-side validation**, you must add the necessary JavaScript files to your view for jQuery validation and unobtrusive validation.==
- ==The **Select Tag Helper** can generate drop-down `<select>` elements as well as list boxes, using the `asp-for` and `asp-items` attributes. To generate a multiselect `<select>` element, bind the element to an `IEnumerable` property on the view model.== You can use these approaches to generate several different styles of select box.
- ==The items supplied in `asp-for` must be an `IEnumerable<SelectListItem>`. If you try to bind another type, you’ll get a compile time error in your Razor view.==
- ==You can generate an `IEnumerable<SelectListItem>` for an `enum TEnum` using the `Html.GetEnumSelectList<TEnum>()` helper method. ==This saves you having to write the mapping code yourself.
- ==The **Select Tag Helper** will generate `<optgroup>` elements if the items supplied in `asp-for` have an associated `SelectListGroup` on the Group property. Groups are can be used to separate items in select lists.==
- ==Any extra additional `<option>` elements added to the Razor markup will be passed through to the final HTML. You can use these additional elements to easily add a *“no selection”* option to the `<select>` element.==
- ==The **Validation Message Tag Helper** is used to render the **client- and server-side validation** error messages for a given property. This gives important feedback to your users when elements have errors. Use the `asp-validation-for` attribute to attach the Validation Message Tag Helper to a `<span>`.==
- ==The **Validation Summary Tag Helper** is used to display validation errors for the model, as well as for individual properties. You can use model-level properties to display additional validation that doesn’t apply to just one property. Use the `asp-validation-summary` attribute to attach the Validation Summary Tag Helper to a `<div>`.==