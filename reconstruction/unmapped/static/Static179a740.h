// Source exposure: binary-analysis; no external implementation source reused.
// Static179a740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179a740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179a740*);
    virtual void release(Static179a740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179a740*);
struct Static179a740 {
    void* value;
    Static179a740();
    ~Static179a740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
