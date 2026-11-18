// Source exposure: binary-analysis; no external implementation source reused.
// Static176f890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f890*);
    virtual void release(Static176f890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f890*);
struct Static176f890 {
    void* value;
    Static176f890();
    ~Static176f890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
