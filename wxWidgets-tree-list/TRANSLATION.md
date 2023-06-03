# Translation

This project is setup to support translating strings. This project does not implement translations. That will be done in another project example.

## Strings
For strings that should not be translated, use wxNT(param). Example:
 - wxNT("Do not translate this message")

For strings that should be translated, use wxT(param). Example:
 - wxT("Translate this message") or _("Translate this message") 

Unwrapped strings are supported. I prefer to use wxNT and wxT as this is easier to search for and shows intent during code reviews.

## Extract Strings from Source Code
To extract the programs strings, use `xgettext`. I use the tools from [poedit](https://poedit.net/). Tested with version 3.3.1.

Add the path to the Poedit tools to your path. On my Windows system, the binaries are located:
 - c:\Program Files (x86)\Poedit
 - c:\Program Files (x86)\Poedit\GettextTools"\bin

Example poedit command. This extracts the strings from the src directory and writes to app.po:
 - `xgettext -C --keyword=wxT --no-wrap -o app.po src\*.cpp`

I have provided an example command in `tools/extract_strings`.

## Translate
Send the file app.po to your translator. They should translate the strings in app.po and return a file with the language in the file name. Example: `app-ja_JP.po`.

## Compile Translation
To compile app.po into app.mo:
 - `msgfmt -o app.mo app.po`

I have provided an example command in `tools/compile_strings`.

You might receive this warning:
 - app.po: warning: Charset "CHARSET" is not a portable encoding name. Message conversion to user's charset might not work.

To correct, open app.po in your editor and replace this line:
 - "Content-Type: text/plain; charset=CHARSET\n"

with this line:
 - "Content-Type: text/plain; charset=UTF-8\n"

Note: confirm that your translator is using UTF-8. Almost all do unless requested to use another charset.

## More Information
 - [wxWidgets Internationalization](https://wiki.wxwidgets.org/Internationalization)
 - [wxWidgets Language Identifiers](https://docs.wxwidgets.org/3.0/language_8h.html)
