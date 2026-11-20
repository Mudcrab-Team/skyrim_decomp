// Source exposure: binary-analysis; no external implementation source reused.
// Static1764210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764210*);
    virtual void release(Static1764210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764210*);
struct Static1764210 {
    void* value;
    Static1764210();
    ~Static1764210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
