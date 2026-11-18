// Source exposure: binary-analysis; no external implementation source reused.
// Static175c740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c740*);
    virtual void release(Static175c740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c740*);
struct Static175c740 {
    void* value;
    Static175c740();
    ~Static175c740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
