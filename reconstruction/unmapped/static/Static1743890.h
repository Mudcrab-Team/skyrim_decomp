// Source exposure: binary-analysis; no external implementation source reused.
// Static1743890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743890*);
    virtual void release(Static1743890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743890*);
struct Static1743890 {
    void* value;
    Static1743890();
    ~Static1743890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
