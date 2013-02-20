#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdio.h>

#include "dl_writer_ascii.h"
#include "dl_exception.h"


/**
 * Closes the output file.
 */
void DL_WriterA::close() const {
    m_ofile.close();
}


/**
 * @retval true Opening file has failed.
 * @retval false Otherwise.
 */
bool DL_WriterA::openFailed() const {
	return m_ofile.fail();
}



/**
 * Writes a real (double) variable to the DXF file.
 *
 * @param gc Group code.
 * @param value Double value
 */
void DL_WriterA::dxfReal(int gc, double value) const {
    char str[256];
    sprintf(str, "%.16lf", value);
	
	// fix for german locale:
	strReplace(str, ',', '.');

    // Cut away those zeros at the end:
    bool dot = false;
    int end = -1;
    for (unsigned int i=0; i<strlen(str); ++i) {
        if (str[i]=='.') {
            dot = true;
            end = i+2;
            continue;
        } else if (dot && str[i]!='0') {
            end = i+1;
        }
    }
    if (end>0 && end<(int)strlen(str)) {
        str[end] = '\0';
    }

    dxfString(gc, str);
    m_ofile.flush();
}



/**
 * Writes an int variable to the DXF file.
 *
 * @param gc Group code.
 * @param value Int value
 */
void DL_WriterA::dxfInt(int gc, int value) const {
    m_ofile << (gc<10 ? "  " : (gc<100 ? " " : "")) << gc << "\n"
    << value << "\n";
}



/**
 * Writes a hex int variable to the DXF file.
 *
 * @param gc Group code.
 * @param value Int value
 */
void DL_WriterA::dxfHex(int gc, int value) const {
    char str[12];
    sprintf(str, "%0X", value);
    dxfString(gc, str);
}



/**
 * Writes a string variable to the DXF file.
 *
 * @param gc Group code.
 * @param value String
 */
void DL_WriterA::dxfString(int gc, const char* value) const {
    if (value==NULL) {
#ifndef __GCC2x__
        //throw DL_NullStrExc();
#endif
    }
    m_ofile << (gc<10 ? "  " : (gc<100 ? " " : "")) << gc << "\n"
    << value << "\n";
}



void DL_WriterA::dxfString(int gc, const string& value) const {
    m_ofile << (gc<10 ? "  " : (gc<100 ? " " : "")) << gc << "\n"
    << value << "\n";
}


/**
 * Replaces every occurence of src with dest in the null terminated str.
 */
void DL_WriterA::strReplace(char* str, char src, char dest) {
	size_t i;
	for	(i=0; i<strlen(str); i++) {
		if (str[i]==src) {
			str[i] = dest;
		}
	}
}

