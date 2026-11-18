// Source exposure: binary-analysis; no external implementation source reused.
// Static1754450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754450*);
    virtual void release(Static1754450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754450*);
struct Static1754450 {
    void* value;
    Static1754450();
    ~Static1754450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
