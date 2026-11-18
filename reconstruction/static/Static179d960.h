// Source exposure: binary-analysis; no external implementation source reused.
// Static179d960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d960*);
    virtual void release(Static179d960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d960*);
struct Static179d960 {
    void* value;
    Static179d960();
    ~Static179d960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
