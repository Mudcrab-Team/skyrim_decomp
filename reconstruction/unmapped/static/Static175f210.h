// Source exposure: binary-analysis; no external implementation source reused.
// Static175f210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f210*);
    virtual void release(Static175f210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f210*);
struct Static175f210 {
    void* value;
    Static175f210();
    ~Static175f210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
