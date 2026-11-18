// Source exposure: binary-analysis; no external implementation source reused.
// Static178c740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c740*);
    virtual void release(Static178c740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c740*);
struct Static178c740 {
    void* value;
    Static178c740();
    ~Static178c740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
