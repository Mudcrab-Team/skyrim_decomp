// Source exposure: binary-analysis; no external implementation source reused.
// Static178f210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f210*);
    virtual void release(Static178f210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f210*);
struct Static178f210 {
    void* value;
    Static178f210();
    ~Static178f210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
