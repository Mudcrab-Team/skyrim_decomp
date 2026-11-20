// Source exposure: binary-analysis; no external implementation source reused.
// Static178c560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c560*);
    virtual void release(Static178c560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c560*);
struct Static178c560 {
    void* value;
    Static178c560();
    ~Static178c560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
