#ifndef ENUMCFG__H
#define ENUMCFG__H

// Note! the hashMap definition in this header is a lazy way of having the hashMap type; do not use!! (use <enum>::enumContainer instead)

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__)  || defined( __MWERKS__)
#  ifdef EXPORT_LIBRARY
#    define EXPORT_MACRO __declspec(dllexport)
#  else
#    define EXPORT_MACRO  __declspec(dllimport)
#  endif
//Get the proper header that defines hash map:
//  VC++ < v7.1 in header "hash_map" in namespace std.
//  VC++ >= v7.1 in header "hash_map" in namespace stdext
#  ifdef _MSC_VER
#    include <hash_map>
#    if _MSC_VER < 1310
#      define hashMap std::hash_map
#    else
#      define hashMap stdext::hash_map
#    endif
#  else
#    include <map>
#    define  hashMap std::map
#  endif
#else
#  define EXPORT_MACRO
   //Get the proper header that defines hash map:
   //  GCC >= 4.* series in header "tr1/unordered_map" it's called unordered_map and it's in namespace std::tr1
   //  GCC < 4.* series in header "ext/hash_map" in namespace __gnu_cxx.
#  ifdef __GNUC__
#    if __GNUC__ > 3
#      include <tr1/unordered_map>
#      define hashMap std::tr1::unordered_map
#    else
#      include <ext/hash_map>
#      define hashMap __gnu_cxx::hash_map
#    endif
#  else
#    include <map>
#    define  hashMap std::map
#  endif
#endif

#endif /* ENUMCFG__H */
