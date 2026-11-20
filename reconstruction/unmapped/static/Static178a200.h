// Source exposure: binary-analysis; no external implementation source reused.
// Static178a200, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a200;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a200*);
    virtual void release(Static178a200*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a200*);
struct Static178a200 {
    void* value;
    Static178a200();
    ~Static178a200() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
