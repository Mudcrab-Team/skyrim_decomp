// Source exposure: binary-analysis; no external implementation source reused.
// Static17acf80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17acf80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17acf80*);
    virtual void release(Static17acf80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17acf80*);
struct Static17acf80 {
    void* value;
    Static17acf80();
    ~Static17acf80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
