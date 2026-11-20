// Source exposure: binary-analysis; no external implementation source reused.
// Static1748690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1748690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1748690*);
    virtual void release(Static1748690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1748690*);
struct Static1748690 {
    void* value;
    Static1748690();
    ~Static1748690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
