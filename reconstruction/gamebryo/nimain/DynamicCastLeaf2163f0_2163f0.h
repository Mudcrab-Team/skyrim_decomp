// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// DynamicCast: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and members: GUESS(low); observed target access pattern.
#pragma once

struct CastTypeLeaf2163f0
{
    const char* name;
    const CastTypeLeaf2163f0* parent;
};

class CastObjectLeaf2163f0
{
public:
    virtual ~CastObjectLeaf2163f0();
    virtual void DeleteThis();
    virtual const CastTypeLeaf2163f0* GetType() const;
};

class DynamicCastLeaf2163f0
{
public:
    static CastObjectLeaf2163f0* Cast(const CastTypeLeaf2163f0*, CastObjectLeaf2163f0*);
};
