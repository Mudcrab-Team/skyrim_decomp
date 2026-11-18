// Source exposure: binary-analysis; no external implementation source reused.
// Static173ef60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ef60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ef60*);
    virtual void release(Static173ef60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ef60*);
struct Static173ef60 {
    void* value;
    Static173ef60();
    ~Static173ef60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
