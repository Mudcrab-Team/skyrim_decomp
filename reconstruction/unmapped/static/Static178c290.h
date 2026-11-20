// Source exposure: binary-analysis; no external implementation source reused.
// Static178c290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c290*);
    virtual void release(Static178c290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c290*);
struct Static178c290 {
    void* value;
    Static178c290();
    ~Static178c290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
