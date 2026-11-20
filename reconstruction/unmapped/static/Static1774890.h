// Source exposure: binary-analysis; no external implementation source reused.
// Static1774890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774890*);
    virtual void release(Static1774890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774890*);
struct Static1774890 {
    void* value;
    Static1774890();
    ~Static1774890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
