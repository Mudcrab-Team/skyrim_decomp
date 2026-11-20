// Source exposure: binary-analysis; no external implementation source reused.
// Static178d920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d920*);
    virtual void release(Static178d920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d920*);
struct Static178d920 {
    void* value;
    Static178d920();
    ~Static178d920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
