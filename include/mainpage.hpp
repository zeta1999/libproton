/** @mainpage C++11 Proton Library
*
* @authors <a href="http://lenx.100871.net">Lenx Tao Wei</a> (lenx.wei at gmail.com)
*
* @section intro Introduction
* Proton is a library to make C++11 as convenient as Python :) <br>
* The main git repository is at https://github.com/LenxWei/libproton.
*
* @section install Install
* Download site:
* - http://code.google.com/p/libproton/downloads/list
* - https://github.com/LenxWei/libproton/downloads
*
* Need a compiler supporting c++11, such as gcc 4.7.0 or higher.<br>
* Install <a href="http://www.boost.org/">Boost C++ Library</a> 1.48 or higher first.
*
* After that, just standard "./configure; make; make check; make install"
*
* @section modules Modules
* You can find documents about modules <a href="modules.html">here</a>.
* <hr>
* @todo add proton containers for stl containers
* @todo add examples
* @todo add tutorial
* @todo add threading support at 1.4
* @todo add gc support at 1.6
*
* @defgroup ref Smart reference
* Provide basic reference support for proton.
* @{
*  @defgroup ref_ ref_
*  Core reference template.
*
*  @defgroup functor func_
*  General functor interface template.
*
* @}
*
* @defgroup stl Containers
* Repack stl containers in new templates following python's habits.
* @{
*  @defgroup vector_ vector_
*  like list in python.
*
* @}
*
* @defgroup util Utilities
* @{
*
*  @defgroup debug Debug utilities
*  Macros, global variables, classes for debug.
*
*  @defgroup pool Smart allocator
*  A high-performance and smart allocator.
*
* @}
*
*/
