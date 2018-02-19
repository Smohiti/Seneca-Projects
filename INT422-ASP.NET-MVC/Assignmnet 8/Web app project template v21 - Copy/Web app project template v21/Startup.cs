using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Web_app_project_template_v21.Startup))]
namespace Web_app_project_template_v21
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
