// Source exposure: binary-analysis; no external implementation source reused.
// Static1782620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782620*);
    virtual void release(Static1782620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782620*);
struct Static1782620 {
    void* value;
    Static1782620();
    ~Static1782620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
