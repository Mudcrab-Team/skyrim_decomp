// Source exposure: binary-analysis; no external implementation source reused.
// Static1773620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773620*);
    virtual void release(Static1773620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773620*);
struct Static1773620 {
    void* value;
    Static1773620();
    ~Static1773620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
