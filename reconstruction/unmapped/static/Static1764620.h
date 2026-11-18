// Source exposure: binary-analysis; no external implementation source reused.
// Static1764620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764620*);
    virtual void release(Static1764620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764620*);
struct Static1764620 {
    void* value;
    Static1764620();
    ~Static1764620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
