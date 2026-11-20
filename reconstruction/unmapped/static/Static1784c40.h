// Source exposure: binary-analysis; no external implementation source reused.
// Static1784c40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784c40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784c40*);
    virtual void release(Static1784c40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784c40*);
struct Static1784c40 {
    void* value;
    Static1784c40();
    ~Static1784c40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
