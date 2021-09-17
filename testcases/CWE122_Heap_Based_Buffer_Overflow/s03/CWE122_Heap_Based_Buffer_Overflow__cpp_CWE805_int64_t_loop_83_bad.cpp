/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83_bad.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: loop
 *    BadSink : Copy int64_t array to data using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83_bad::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83_bad(int64_t * dataCopy)
{
    data = dataCopy;
    /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
    data = new int64_t[50];
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83_bad::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_int64_t_loop_83_bad()
{
    {
        int64_t source[100] = {0}; /* fill with 0's */
        {
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data < 100 */
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printLongLongLine(data[0]);
            delete [] data;
        }
    }
}
}
#endif /* OMITBAD */