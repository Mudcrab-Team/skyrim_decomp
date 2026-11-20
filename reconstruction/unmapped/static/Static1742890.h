// Source exposure: binary-analysis; no external implementation source reused.
// Static1742890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742890*);
    virtual void release(Static1742890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742890*);
struct Static1742890 {
    void* value;
    Static1742890();
    ~Static1742890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
