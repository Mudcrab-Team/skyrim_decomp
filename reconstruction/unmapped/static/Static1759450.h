// Source exposure: binary-analysis; no external implementation source reused.
// Static1759450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759450*);
    virtual void release(Static1759450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759450*);
struct Static1759450 {
    void* value;
    Static1759450();
    ~Static1759450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
