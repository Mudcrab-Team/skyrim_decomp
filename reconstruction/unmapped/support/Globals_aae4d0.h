// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkStringBuf: CRASHLOGGER_PDB(59818@2026.10.24)
// hkStringBuf::pathBasename: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

struct Func00d61640_cls
{
    char* m_data;
    int m_fRestLength;

    int FindLastCharInRange(char c, int startIndex, int endIndex);
};

struct Func00d617d0_cls
{
    char* m_p00;
    int m_i04;
    void RemoveFront(int count);
};


struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};

class hkStringBuf
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int FindLastCharInRange(char c, int iStartIndex, int iEndIndex) const;
    void RemoveFront(int n);
    void pathBasename();
};


int Func00d61640_cls::FindLastCharInRange(char c, int startIndex, int endIndex)
{
    if (endIndex > m_fRestLength - 1)
        endIndex = m_fRestLength - 1;

    for (int i = endIndex - 1; i >= startIndex; --i)
    {
        if (m_data[i] == c)
            return i;
    }
    return -1;
}

void Func00d617d0_cls::RemoveFront(int count)
{
    if (count > 0)
    {
        m_i04 -= count;
        int remaining = m_i04;
        char* destination = m_p00;
        char* source = destination + count;
        if (remaining > 0)
        {
            for (int i = 0; i < remaining; ++i)
            {
                destination[i] = source[i];
            }
        }
    }
}

struct Globals
{
};
