// Source exposure: binary-analysis; no external implementation source reused.
// Static1779890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779890*);
    virtual void release(Static1779890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779890*);
struct Static1779890 {
    void* value;
    Static1779890();
    ~Static1779890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
