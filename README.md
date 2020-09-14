# hw3d

This is a sample Direct3D C++ project (Visual Studio 2019 solution) created from an *Empty C++ Project* following the YouTube tutorial playlist [**C++ 3D DirectX Programming**](https://www.youtube.com/watch?v=_4FArgOX1I4&list=PLqCJpWy5Fohd3S7ICFXwUomYW0Wv67pDD&index=1). As a result it should be similar to (but not the same as) [**the tutorial's repository**](https://github.com/planetchili/hw3d) at the point in the tutorial I have reached.

## Differences to Tutorial Repository

The main differences between this repository and the tutorial's repository are going to be due to the following:

* My **hw3d.vcxproj** C++ preprocessor definitions include the Visual Studio project default ```%(PreprocessorDefinitions)``` which in Visual Studio 2019 means ```_UNICODE``` and ```UNICODE``` are defined:
  * I am using the ```W``` version of expanded functions rather than the ```A``` version, and am therefore using ```LPCWSTR``` rather than ```LPCSTR```.
  * My call to ```CreateWindowEx()``` expands to ```CreateWindowExW()``` so my variable for the window title and class name are of a different type to that in the tutorial.
  * I am using ```std::wstringstream``` instead of ```std::ostringstream```, and other types, for the same reason.
* I am likely to use **XML documentation** for the functions, and where a function has an example or definition in Microsoft documentation AKA MSDN I will likely use the same variable names as Microsoft.
  * This should aid the *Search online* option in Visual Studio IntelliSense at finding the function definition in Bing.
  * I will use the non-standard (not currently seen in IntelliSense) ```<seealso href="https://..." />``` to point at the relevant documentation.
  * This is also to help me remember why something is being done a certain way.
* I am not a C++ programmer, so my coding style likely has influences from Java, C, C#, and auto-formatting (```Ctrl+K, Ctrl+D```). I am likely to mix camelCase with PascalCase and Hungarian notation, although my use of snake_case should be limited to ```#define``` and constant/localised resource names.
* I use a mixture of American English and British English in my code and comments.
  * Function names tend to be in American English.
  * Variable names tend to be in British English unless I am using the same names used in documentation or there is a convention I am following (```color``` being an example that is highly inconsistent).
    * Auto-completion of naming new variables after their types will likely be a factor.
  * Comments tend to be in British English unless I am using American English. Some comments will likely switch between the two languages within the same sentence as I reference types, functions, and variables.

## Licensing

The licensing for some of the code in this repository (and therefore the repository as a whole) is ***unknown***. Although I tend to licence my code MIT (Expat), [the tutorial repository](https://github.com/planetchili/hw3d) lacks an overall licence, as do the tutorial videos' descriptions.

A quick GitHub search has some of the tutorial repository's code files licensed GPL 3+, some MIT, some BSD, some dual-licensed, and most of the code from the tutorials themselves lack any copyright and licensing notices.

I am therefore unable to state what licence(s) apply to this repository as a whole or to individual files that lack licensing comments. One could infer the repository as a whole is GPL 3+ as it will contain GPL 3+ licensed source code, but I'm not willing to make that determination.

### Code Deviations from Tutorial Repository

As my deviations from [the tutorial repository](https://github.com/planetchili/hw3d) and videos are likely to be minuscule or uncopyrightable, I am triple-licensing my deviations [**CC0 1.0**](https://creativecommons.org/publicdomain/zero/1.0/), [**The Unlicense**](https://opensource.org/licenses/unlicense), and [**0BSD**](https://opensource.org/licenses/0BSD) where they do not otherwise state a licence.

This does not cover deviations that are derived from code in [the tutorial repository](https://github.com/planetchili/hw3d) and/or tutorial videos&mdash;I am unable to relicense derivative code where the upstream source has an unknown/incompatible licence.

For clarity, where the public domain equivalent licences above mention compiling, distributing, binaries, etc., it should be impossible for my deviations to be compiled as they are almost certainly incomplete code.

The following function is an example of code that is not covered by this section because it is derived from the tutorial video (changing window title based on keyboard key F being pressed). It doesn't actually perform that function (it just returns a string), and it is so obvious that it is almost certainly uncopyrightable, but it is nonetheless derived from an idea in one of the tutorial videos and is therefore excluded.

```cpp
/// <summary>
/// Get applicable window title
/// </summary>
/// <param name="useAlt">Whether the alternative title should be used.</param>
/// <returns>The window title the window should use.</returns>
LPCWSTR GetWindowTitle(bool useAlt = false)
{
	return useAlt ? L"F is pressed!" : L"Main Window";
}
```
