// Source exposure: binary-analysis; no external implementation source reused.
// Static173f890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f890*);
    virtual void release(Static173f890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f890*);
struct Static173f890 {
    void* value;
    Static173f890();
    ~Static173f890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
