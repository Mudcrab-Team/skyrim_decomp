// Source exposure: binary-analysis; no external implementation source reused.
// Static1743990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743990*);
    virtual void release(Static1743990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743990*);
struct Static1743990 {
    void* value;
    Static1743990();
    ~Static1743990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
