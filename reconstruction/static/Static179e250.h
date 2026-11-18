// Source exposure: binary-analysis; no external implementation source reused.
// Static179e250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e250*);
    virtual void release(Static179e250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e250*);
struct Static179e250 {
    void* value;
    Static179e250();
    ~Static179e250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
