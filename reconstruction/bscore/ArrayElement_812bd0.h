// Source exposure: mixed (compiler-generated helper; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ArrayElement, ArrayHolder: GUESS(low)
#pragma once

struct ArrayElement
{
    ArrayElement(const ArrayElement& other);
    char data[24];
};

struct ArrayHolder
{
    ArrayElement elements[8];
};

ArrayHolder CopyHolder(const ArrayHolder& other);
