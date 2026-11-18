// Source exposure: binary-analysis; no external implementation source reused.
// Static179c340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c340*);
    virtual void release(Static179c340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c340*);
struct Static179c340 {
    void* value;
    Static179c340();
    ~Static179c340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
