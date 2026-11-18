// Source exposure: binary-analysis; no external implementation source reused.
// Static1764e40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764e40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764e40*);
    virtual void release(Static1764e40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764e40*);
struct Static1764e40 {
    void* value;
    Static1764e40();
    ~Static1764e40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
