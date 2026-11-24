// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// SolveMatrixColumns: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct MatrixNm;


struct MatResult
{
    bool m_ok;
    MatResult()
    {}
};

struct MatrixNm
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_numRows;
    int m_numCols;

    MatrixNm(int numRows, int numCols);
    void Release();
    int GetNumRows() const;
    int GetNumCols() const;
    float* GetPtr(int row, int col);
    float* GetVecPtr(int i);
    float Get(int row, int col);
};

MatResult SolveVector(void* solver, MatrixNm& x, MatrixNm& b, int maxIter, float tolerance);

struct Globals
{
};
