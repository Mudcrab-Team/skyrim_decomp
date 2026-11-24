// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: SolveMatrixColumns.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramcreatorhlsl.cpp:870
// 0xcb8f10 SolveMatrixColumns
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramcreatorhlsl.cpp:789
#include "Globals_cb8f10.h"

MatResult SolveMatrixColumns(void* solver, MatrixNm& x, MatrixNm& b, int maxIter, float tolerance)
{
    MatResult result;
    MatrixNm xColumn(x.GetNumRows(), 1);
    MatrixNm bColumn(b.GetNumRows(), 1);
    for (int col = 0; col < x.GetNumCols(); col++)
    {
        int row;
        for (row = 0; row < x.GetNumRows(); row++)
        {
            *xColumn.GetVecPtr(row) = *x.GetPtr(row, col);
            float fValue = b.Get(row, col);
            *bColumn.GetVecPtr(row) = fValue;
        }
        if (!SolveVector(solver, xColumn, bColumn, maxIter, tolerance).m_ok)
        {
            result.m_ok = false;
            bColumn.Release();
            xColumn.Release();
            return result;
        }
        for (row = 0; row < x.GetNumRows(); row++)
        {
            *x.GetPtr(row, col) = *xColumn.GetVecPtr(row);
        }
    }
    result.m_ok = true;
    bColumn.Release();
    xColumn.Release();
    return result;
}
