// Source exposure: binary-analysis; no external implementation source reused.
// Static1786950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786950*);
    virtual void release(Static1786950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786950*);
struct Static1786950 {
    void* value;
    Static1786950();
    ~Static1786950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
