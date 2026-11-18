// Source exposure: binary-analysis; no external implementation source reused.
// Static1783700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1783700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1783700*);
    virtual void release(Static1783700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1783700*);
struct Static1783700 {
    void* value;
    Static1783700();
    ~Static1783700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
