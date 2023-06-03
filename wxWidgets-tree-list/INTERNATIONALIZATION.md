# Internationalization (I18N)

This example project does not use the translation files (*.mo). This will be demonstrated in a future project.

The translated *.mo files are called Catalogs. Review the [wxLocale](https://docs.wxwidgets.org/3.0/classwx_locale.html) class for more details.
 - `wxLocale(language)` sets the language. For example, `wxLANGUAGE_JAPANESE` (ja-JP).
 - The member `AddCatalog()` loads the correct *.mo file for the selected language.
 - Review the commented section in `MyApp::OnInit()` in src/mainapp.cpp.

```
// This is for future internationalization
// Catalogs is the path to where the translation app.mo files are located.
// [absolute path]/Catalogs
// For example, under Catalogs/ja_JP is is the Japanese translation file app.mo.
// The catalog files are included in the application installer.
// For exmaple on Windows:
// - C:/Program Files/My App/
// -- main.exe
// -- Catalogs/
// -- Catalogs/es_ES/app.mo	(Spanish translation)
// -- Catalogs/ja_JP/app.mo	(Japanese translation)
//
// m_locale = new wxLocale(wxLANGUAGE_JAPANESE);
// wxString catalogs = "/path/to/Catalogs";	// Directory path
// m_locale->AddCatalogPrefixPath(catalogs);
// m_locale->AddCatalog(wxNT("app"));		// Loads Catalogs/ja_JP/app.mo
```

## More Information
 - [wxWidgets Internationalization](https://wiki.wxwidgets.org/Internationalization)
 - [wxWidgets Language Identifiers](https://docs.wxwidgets.org/3.0/language_8h.html)
