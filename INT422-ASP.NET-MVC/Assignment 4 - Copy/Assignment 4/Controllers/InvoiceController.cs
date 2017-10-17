using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Assignment_4.Controllers
{

    public class InvoiceController : Controller
    {
        private Manager m = new Manager();
        // GET: Invoice
        public ActionResult Index()
        {
            var c = m.InvoiveGetAll();
            return View(c);
        }
        public ActionResult Details(int? id)
        {
            var c = m.InvoiceGetByIdWithDetail(id.GetValueOrDefault());
            if (c == null)
            {
                return HttpNotFound();

            }
            else
            {
                return View(c);
            }
        }

    }
}