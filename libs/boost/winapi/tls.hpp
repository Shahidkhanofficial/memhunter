/*
 * Copyright 2013 Andrey Semashev
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_TLS_HPP_INCLUDED_
#define BOOST_WINAPI_TLS_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_APP_SYSTEM

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {
#if !defined( UNDER_CE )
// Windows CE define TlsAlloc and TlsFree as inline functions in kfuncs.h
BOOST_SYMBOL_IMPORT boost::winapi::DWORD_ WINAPI
TlsAlloc(BOOST_WINAPI_DETAIL_VOID);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
TlsFree(boost::winapi::DWORD_ dwTlsIndex);
#endif

BOOST_SYMBOL_IMPORT boost::winapi::LPVOID_ WINAPI
TlsGetValue(boost::winapi::DWORD_ dwTlsIndex);

BOOST_SYMBOL_IMPORT boost::winapi::BOOL_ WINAPI
TlsSetValue(
    boost::winapi::DWORD_ dwTlsIndex,
    boost::winapi::LPVOID_ lpTlsValue);
} // extern "C"
#endif

namespace boost {
namespace winapi {

using ::TlsAlloc;
using ::TlsFree;
using ::TlsGetValue;
using ::TlsSetValue;

#if defined( BOOST_USE_WINDOWS_H )
const DWORD_ TLS_OUT_OF_INDEXES_ = TLS_OUT_OF_INDEXES;
#else
const DWORD_ TLS_OUT_OF_INDEXES_ = 0xFFFFFFFF;
#endif

const DWORD_ tls_out_of_indexes = TLS_OUT_OF_INDEXES_;

}
}

#endif // BOOST_WINAPI_PARTITION_APP_SYSTEM
#endif // BOOST_WINAPI_TLS_HPP_INCLUDED_
